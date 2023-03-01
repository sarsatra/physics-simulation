#ifndef OBJECT_H
#define OBJECT_H

#include "vector.h"

#include <glad/glad.h>

typedef struct
{
    GLuint *collide;
    GLuint collide_count;
} Collision;

typedef enum
{
    black,
    white,
    yellow,
    green,
    red,
    blue,
    cyan
} Color;

typedef enum
{
    rectangle,
    circle /* Unavailable now */
} Shape_t;

typedef struct
{
    Shape_t shape;
    Vector2 size; /* Width and height */
    GLfloat radius;
} Shape;

typedef struct
{
    Vector2 position;
    Color color;
    GLuint id;

    Shape *shape;
    Collision *collision;
} Object;

typedef struct
{
    GLuint object_count;
    GLuint vao;
    GLuint ebo; 
    GLuint move;
    GLuint model;
    GLuint color;
    GLuint *indices_circle;
    GLfloat *unit_circle;
    Object **objects;
} Renderer;

Object *InitializeObject(Vector2 position, Shape_t shape, Vector2 size, GLfloat radius, Color color, Renderer *renderer);

Renderer *InitializeRenderer(GLuint program_id);

void RenderObjects(Renderer *renderer, GLuint program_id);

#include "collision.h"

#endif
