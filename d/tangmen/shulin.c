// Room: /d/tangmen/shulin.c

inherit VRM_SERVER;

void create()
{
	set_inherit_room( __DIR__"lin" );

	set_maze_long(8);

	//��ڷ���(�����ڶ���)
	set_entry_dir("south");

	//�������������ӷ���
	set_link_entry_dir("south");

	set_link_entry_room(__DIR__"gd1");

	set_link_exit_dir("north");

	set_link_exit_room(__DIR__"dmq");

	set_entry_short("Ũ������");

	//��ڷ�������
	set_entry_desc(@LONG
������һƬŨ�ܵ����֣�����Ĵ���������գ�ż���м���
����͸�������������ǿ�֦��Ҷ�����������������˲��������ա�
LONG
);

	//���ڷ��������
	set_exit_short("Ũ������");

	//���ڷ�������
	set_exit_desc(@LONG
������һƬŨ�ܵ����֣�����Ĵ���������գ�ż���м���
����͸�������������ǿ�֦��Ҷ�����������������˲��������ա�
LONG
);

	set_outdoors(1);

	set_valid_rooms( ({
	__DIR__"lin",
}));

	create_maze();
}

string query_my_map()
{
	return read_file(__DIR__"shulin.map");
}

