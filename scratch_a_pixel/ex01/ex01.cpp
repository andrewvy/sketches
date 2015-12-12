#include <cstdlib>
#include <cstdio>

// Define Point as an array of 3 floats
typedef float Point[3];

int main() {
  // Define corners as a fixed 8-elem array
  // of points
  Point corners[8] = {
    { 1, -1, -5 },
    { 1, -1, -3 },
    { 1, 1, -5 },
    { 1, 1, -3 },
    { -1, -1, -5 },
    { -1, -1, -3 },
    { -1, 1, -5 },
    { -1, 1, -3 }
  };

  const unsigned int image_width = 512;
  const unsigned int image_height = 512;

  for (int i = 0; i < 8; ++i) {
    // Divide the x and y coordinates by the z coordinate to
    // project the point on the canvas.
    float x_proj = corners[i][0] / -corners[i][2];
    float y_proj = corners[i][1] / -corners[i][2];

    // This normalizes the projected coords to be
    // a float from 0 - 1
    float x_proj_remap = (1 + x_proj) / 2;
    float y_proj_remap = (1 + y_proj) / 2;

    // Then we can take the normalized coords and
    // multiply by whatever our image dimensions are.
    float x_proj_pix = x_proj_remap * image_width;
    float y_proj_pix = y_proj_remap * image_height;

    // These resulting coordinates are said to be in
    // a raster space.
    printf("corner: %d x:%f y:%f\n", i, x_proj_pix, y_proj_pix);

  }

  return 0;
}
