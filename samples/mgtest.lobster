// graphics demo showing Lobster's builtin facilities of generating meshes procedurally from implicit functions
// this functionality is under construction

import vec
import color
import gl
import camera
import gl
import mg

print "generating models... this may take some time!"

fatal(gl_window("meshgen test (PLEASE WAIT...)", 1280, 800, gl_window_init_linear_color))

let camera = Camera { xyz { 10.0, 10.0, 10.0 }, 135, 0 }

def mg_mirror_y(dist, body):
    for(2) i:
        mg_translate(xyz { 0.0, i * dist * 2.0 - dist, 0.0 }, body)

//mg_set_color_noise(0.5, 1)
let aspoints = false
mg_set_point_mode(aspoints)
if not aspoints:
    //mg_set_polygon_reduction(3, 0.98, 0.95)
    mg_set_vertex_randomize(0)

let density = 80

var abstract = nil
if true:
    mg_smooth(1)
    mg_color(color_white)
    mg_rotate(xyz_1, 45):
        //mg_cube(xyz_1)
        mg_superquadric(xyz_1 * 10, xyz_1)  // Cube with rounded edges
    abstract = mg_polygonize(density)

var gun = nil
if true:
    mg_smooth(0.5)
    mg_color(color_white)
    mg_rotate(xyz_y, 90.0):
        mg_scale_vec(xyz { 1.0, 1.3, 1.0 }):
            mg_supertoroid(3.0, xyz { 3.0, 3.0, 5.0 })
    mg_translate(xyz { 0.0, -1.3, 2.0 }):
        mg_rotate(xyz_x, 20.0):
            mg_superquadric(xyz { 3.0, 3.0, 3.0 }, xyz { 0.5, 0.5, 3.5 })
    mg_translate(xyz { 0.0, -8.0, 4.0 }):
        mg_rotate(xyz_x, 30.0):
            mg_superquadric(xyz { 3.0, 3.0, 3.0 }, xyz { 0.5, 0.5, 2.5 })
    mg_translate(xyz { 0.0, -5.5, -3.0 }):
        mg_rotate(xyz_x, -20.0):
            mg_superquadric(xyz { 5.0, 5.0, 100.0 }, xyz { 1.5, 2.5, 6.5 })
    mg_translate(xyz { 0.0, 2.0, 4.2 }):
        mg_superquadric(xyz { 3.0, 100.0, 3.0 }, xyz { 2.0, 10.0, 3.0 })
    mg_translate(xyz { 0.0, 14.0, 5.0 }):
        mg_rotate(xyz_x, 90.0):
            mg_cylinder(1, 3)
    gun = mg_polygonize(density)

var spaceship = nil
if true:
    mg_smooth(0.5)
    mg_color(color_white)
    mg_superquadric_non_uniform(xyz { 1.0, 2.0, 2.0 }, xyz { 2.0, 2.0, 2.0 },
                                xyz { 2.0, 3.5, 0.3 }, xyz { 0.5, 3.5, 0.3 })
    mg_superquadric_non_uniform(xyz { 2.0, 1.5, 1.0 }, xyz { 2.0, 1.5, 2.0 },
                                xyz { 4.0, 1.0, 0.7 }, xyz { 0.7, 1.0, 0.4 })
    mg_translate(xyz { 1.0, 0.0, 0.4 }):
        mg_superquadric_non_uniform(xyz { 2.0, 2.0, 1.0 }, xyz { 2.0, 2.0, 2.0 },
                                    xyz { 1.0, 0.5, 0.4 }, xyz { 0.5, 0.5, 0.5 })
    mg_mirror_y(1.5):
        mg_translate(xyz_x):
            mg_superquadric(xyz { 100.0, 2.0, 2.0 }, xyz { 1.3, 0.2, 0.2 })
    mg_mirror_y(2):
        mg_translate(xyz_x):
            mg_superquadric(xyz { 100.0, 2.0, 2.0 }, xyz { 1.0, 0.15, 0.15 })
    mg_mirror_y(1):
        mg_translate(xyz_x * -0.6):
            mg_superquadric_non_uniform(xyz { 1.0, 2.0, 2.0 }, xyz { 1.0, 2.0, 2.0 },
                                        xyz { 1.5, 0.5, 0.5 }, xyz { 0.01, 0.5, 0.5 })
            mg_color(color { 1.0, 1.0, 1.0, 0.0 /* carve */ }):
                mg_rotate(xyz_y, 90.0):
                    mg_smooth(0.0):
                        mg_cylinder(0.35, 0.25)
    spaceship = mg_polygonize(density * 2)

def model_tree(numb, branchl, narrowf, leafs, leafc) -> void:
    if numb:
        mg_translate(xyz_z * branchl):
            mg_tapered_cylinder(1, narrowf, branchl)
            mg_translate(xyz_z * branchl):
                let axis = xyz(sincos(rnd(360)), 0)
                let branches = rnd(3) + 1
                for(branches) i:
                    mg_rotate(xyz_z, 360 * i / branches):
                        mg_rotate(axis, 12 * branches):
                            mg_scale(narrowf):
                                mg_sphere(1)
                                model_tree(numb - 1, branchl, narrowf, leafs, leafc)
    else:
        mg_color(leafc):
            mg_sphere(leafs)

let trees = []

if true:
    mg_smooth(0.5)
    mg_color(color { 0.6, 0.5, 0.4, 1.0 })
    model_tree(10, 1.5, 0.75, 12, color { 0.4, 1.0, 0.4, 1.0 })
    trees.push(mg_polygonize(density))

    mg_smooth(0.5)
    mg_color(color { 0.4, 0.3, 0.2, 1.0 })
    model_tree(10, 1.2, 0.8, 1.2, color { 0.6, 1.0, 0.3, 1.0 })
    trees.push(mg_polygonize(density))

    mg_smooth(0.5)
    mg_color(color { 0.5, 0.4, 0.3, 1.0 })
    model_tree(9, 2.0, 0.7, 15, color { 0.4, 0.6, 0.4, 1.0 })
    trees.push(mg_polygonize(density))

var landscape = nil
// Currently expensive way to do a landscape.
if true:
    mg_smooth(0.1)
    mg_color(color { 0.6, 0.5, 0.4, 1.0 })
    mg_landscape(0.5, 1.0)
    landscape = mg_polygonize(density)

if gun: print "vertcount: gun {gl_mesh_size(gun)}"
if spaceship: print "vertcount: ship {gl_mesh_size(spaceship)}"
for trees: print("vertcount: tree1 {gl_mesh_size(_)}")
if abstract: print "vertcount: abstract {gl_mesh_size(abstract)}"

print seconds_elapsed()

while gl_frame():
    if gl_button("escape") == 1: return

    gl_window_title("meshgen test: {gl_delta_time()}")

    gl_clear(color_darkest_grey)

    let fovscale = 1.5

    if true:
        gl_cursor(false)
        gl_perspective(60, 0.1, 1000)

        var speed = 10
        if gl_button("left shift") >= 1: speed = 50
        camera.FPS_update("w", "a", "s", "d", speed, 4, true)
        camera.FPS_view()
        gl_light(camera.position, xy { 128.0, 0.1 })
    else:
        gl_ortho3d(xyz_0, xyz_f { gl_window_size().x, gl_window_size().y, 2000 } / 100)
        gl_rotate_x(sincos(45))
        gl_rotate_z(sincos(45))
        gl_light(xyz(sincos(gl_time() * 10), 0) * 100 + xyz_z * 300, xy { 128.0, 0.1 })

    gl_blend 0:
        gl_set_shader(aspoints and "phong_particle" or "flat")

        if spaceship:
            gl_translate(xy_1 * 10):
                gl_point_scale(1 * fovscale)
                gl_render_mesh(spaceship)

        if gun:
            gl_translate(xy_1 * 20):
                gl_scale(0.2):
                    gl_point_scale(0.2 * fovscale)
                    gl_render_mesh(gun)

        if landscape:
            gl_translate(xy_y * 30):
                gl_scale(10):
                    gl_point_scale(10 * fovscale)
                    gl_render_mesh(landscape)

        if abstract:
            gl_translate(xy_y * 10):
                gl_scale(2):
                    gl_point_scale(3 * fovscale)
                    gl_render_mesh(abstract)

        for(10) j:
            gl_translate(xyz_y * j * -5):
                for(trees) t, i:
                    gl_translate(xyz_x * i * 10):
                        gl_scale(0.5):
                            gl_point_scale(0.5 * fovscale)
                            gl_render_mesh(t)

    gl_set_shader("color")
    gl_debug_grid(xyz { 20, 20, 0 }, xyz_1, 0.005)

