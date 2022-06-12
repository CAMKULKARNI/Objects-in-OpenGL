# Objects-in-OpenGL

This project deals with creation and interaction of various objects in OpenGL.
Imagine a hallow sphere at the center of the coordinate frame (0,0,0) . The walls of the sphere are rigid. The insides of the sphere contains a 3D objects that are made of trianlgles, which are trying to escape from the clutches of the sphere, but bouces back again and again (randomly). These objects are rotating(randomly) and moving(randomly) within the boundry of the sphere. This project tries to visulize this scenario with following conditions

The camera is situated on the circumference of the sphere and always pointing at the center of the sphere. The camera's position on the circumference of the sphere should be controled using mouse movements

The objects with in the sphere should be selectable using a left mouse click. Up on selection, the objects should stop its random movement and now move according to the users command. Upon selection, the user should be able to apply transformation (rotation, scaling and translation) depending on the mouse movement or keyboard strokes.

The user-app interaction is done using the following:

* The camera can be navigated using the mouse.
* After selection of the object using the mouse:
  * Pressing A it moves in negative X-axis.
  * Pressing D it moves in positive X-axis.
  * Pressing S it moves in negative Y-axis.
  * Pressing W it moves in positive Y-axis.
  * Pressing E it moves in positive Z-axis.
  * Pressing Q it moves in negative Z-axis.
  * Pressing X it rotates in X axis.
  * Pressing Y it rotates in Y axis.
  * Pressing Z it rotates in Z axis.
  * Pressing P it scales up.
  * Pressing M it scales down.
  * Pressing R resets the object size to original.

These user transformations are also confined within the boundaries of the sphere.

Upon deslection of the object, the object will resume its random movement with the sphere.
