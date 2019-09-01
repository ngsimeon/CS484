// Simeon Ng
// Homework 0
// September 1, 2019
// CS484

#include "pandaFramework.h"
#include "pandaSystem.h"

int main(int argc, char *argv[]) {
	// Load the window and set its title.
	PandaFramework framework;
	framework.open_framework(argc, argv);
	framework.set_window_title("Pizza Clicker");
	WindowFramework *window = framework.open_window();

	window->setup_trackball();

	// Load the environment model.
	NodePath scene = window->load_model(framework.get_models(), "models/pizza");
	// Reparent the model to render.
	scene.reparent_to(window->get_render());
	// Apply scale and position transforms to the model.
	scene.set_pos(0, 0, 0);
	scene.set_hpr(0, 90, 0);

	// Run the engine.
	framework.main_loop();
	// Shut down the engine when done.
	framework.close_framework();
	return 0;
}