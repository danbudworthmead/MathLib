#include "mathLib.h"
#include <iostream>

void main()
{
	AABBCollider2D collider01 = AABBCollider2D(Vector2(150, 150), Vector2(100, 100), false);
	AABBCollider2D collider02 = AABBCollider2D(Vector2(100, 100), Vector2(100, 100), true);

	AABBCollisionManager2D::instance()->Add(collider01);
	AABBCollisionManager2D::instance()->Add(collider02);

	AABBCollisionManager2D::instance()->UpdatePhysics();

	system("pause");
}