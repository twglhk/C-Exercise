#define ACTOR_WIDTH 100
#define ACTOR_SPEED 200

class World
{
	float width, height;

public:
	float getWidth() { return width; }
};

struct Position
{
	float x, y;
};

struct Velocity
{
	float x, y;
};

World world;
Position position;
Velocity velocity;

void update(float deltaTime)
{
	move(deltaTime);
	if (isTurnLeft()) { turnLeft(); }
	if (isTurnRight()) { turnRight(); }
}

// �̵�
void move(float deltatime)
{
	position.x += velocity.x * deltatime;
}

// ������ �� ���ϱ�
float rightBorder()
{
	return world.getWidth() - (ACTOR_WIDTH / 2.0f);
}

// ���� �� ���ϱ�
float leftBorder()
{
	return (ACTOR_WIDTH / 2.0f);
}

// �������� ƨ����� Ȯ��
float isTurnLeft() 
{
	return position.x > rightBorder();
}

// ���������� ƨ����� Ȯ��
float isTurnRight()
{
	return position.x < leftBorder();
}

// �������� ƨ��
void turnLeft()
{
	position.x = rightBorder();
	velocity.x = -ACTOR_SPEED;
}

// ���������� ƨ��
void turnRight()
{
	position.x = leftBorder();
	velocity.x = ACTOR_SPEED;
}