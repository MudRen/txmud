// Room: /d/shaolin/qsl.c

inherit VRM_SERVER;

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room( ROOM );

	//�Թ�������Ĺ��
	//set_maze_npcs(__DIR__"npc/snake");

	//�Թ��ĵ��߳�
	set_maze_long(10);

	//��ڷ���(�����ڶ���)
	set_entry_dir("east");

	//�������������ӷ���
	set_link_entry_dir("east");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"qhs2");

	//��������������ӷ���
	set_link_exit_dir("west");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"qhs3");

	//��ڷ��������
	set_entry_short("��ľ��");

	//��ڷ�������
	set_entry_desc(@LONG
������һƬŨ�ܵ�С��ľ�ԣ���������ԶԶ��ȥ��һ�����
������һ��ɽ�紵������ɳɳ���죬����һ����ɭ�ֲ��ĸо���
LONG
);

	//���ڷ��������
	set_exit_short("��ľ��");

	//���ڷ�������
	set_exit_desc(@LONG
������һƬŨ�ܵ�С��ľ�ԣ���������ԶԶ��ȥ��һ�����
������һ��ɽ�紵������ɳɳ���죬����һ����ɭ�ֲ��ĸо���
LONG
);
/*
	//�Թ�����Ķ�����
	set_maze_room_short("��ľ��");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
������һƬŨ�ܵ�С��ľ�ԣ���������ԶԶ��ȥ��һ�����
������һ��ɽ�紵������ɳɳ���죬����һ����ɭ�ֲ��ĸо���
LONG
);
*/

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(1);

	set_valid_rooms( ({
	__DIR__"qsl_snake",
	__DIR__"qsl_snake",
	__DIR__"qsl_room",
}));
}
