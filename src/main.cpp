#include "opengl-framework/opengl-framework.hpp" // Inclue la librairie qui va nous servir à faire du rendu

int main()
{
    // Initialisation
    gl::init("TPs de Rendering"); // On crée une fenêtre et on choisit son nom
    gl::maximize_window(); // On peut la maximiser si on veut
    glEnable(GL_BLEND);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA, GL_ONE); // On peut configurer l'équation qui mélange deux couleurs, comme pour faire différents blend mode dans Photoshop. Cette équation-ci donne le blending "normal" entre pixels transparents.


    auto const shader = gl::Shader{ {
        .vertex = gl::ShaderSource::File{"res/vertex.glsl"},
        .fragment = gl::ShaderSource::File{"res/fragment.glsl"},
    } };

    auto const triangle_mesh = gl::Mesh{ {
        .vertex_buffers = {{
            .layout = {gl::VertexAttribute::Position2D{0}},
            .data = {
                -0.5f, -0.5f, // Position2D du 1er sommet
                +0.5f, -0.5f, // Position2D du 2ème sommet
                +0.5f, +0.5f, // Position2D du 3ème sommet
                -0.5f, +0.5f  // Position2D du 4ème sommet
            },
        }},
        .index_buffer = {
            0, 1, 2, // Indices du premier triangle : on utilise le 1er, 2ème et 3ème sommet
            0, 2, 3  // Indices du deuxième triangle : on utilise le 1er, 3ème et 4ème sommet
        },
    } };

    auto const triangle_mesh = gl::Mesh{ {
    .vertex_buffers = {{
        .layout = {gl::VertexAttribute::Position2D{0}},
        .data = {
            -0.5f, -0.5f, // Position2D du 1er sommet
            +0.5f, -0.5f, // Position2D du 2ème sommet
            +0.5f, +0.5f, // Position2D du 3ème sommet
            -0.5f, +0.5f  // Position2D du 4ème sommet
        },
    }},
    .index_buffer = {
        0, 1, 2, // Indices du premier triangle : on utilise le 1er, 2ème et 3ème sommet
        0, 2, 3  // Indices du deuxième triangle : on utilise le 1er, 3ème et 4ème sommet
    },
} };



    while (gl::window_is_open())
    {
        glClearColor(0.f, 0.f, 1.f, 1.f); // Choisis la couleur à utiliser. Les paramètres sont R, G, B, A avec des valeurs qui vont de 0 à 1
        glClear(GL_COLOR_BUFFER_BIT); // Exécute concrètement l'action d'appliquer sur tout l'écran la couleur choisie au-dessus
        // Rendu à chaque frame
        shader.bind(); // On a besoin qu'un shader soit bind (i.e. "actif") avant de draw(). On en reparle dans la section d'après.
        shader.set_uniform("_uniforme", glm::vec2{ 1.f, 3.f });
        shader.set_uniform("_aspectRatio", gl::framebuffer_aspect_ratio());
        shader.set_uniform("_time", gl::time_in_seconds());
        shader.set_uniform("_trans", gl::time_in_seconds());


        gl::Mesh trail = triangle_mesh;
        triangle_mesh.draw(); // C'est ce qu'on appelle un "draw call" : on envoie l'instruction à la carte graphique de dessiner notre mesh.
    }

}