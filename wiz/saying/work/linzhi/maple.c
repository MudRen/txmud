//maple.c �������Թ�

inherit VRM_SERVER;

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
    set_inherit_room(ROOM);

	//�Թ�������Ĺ��
{
        if (random(11)>10)
    set_maze_npcs("/d/tianshui/npc/bird");
}

	//�Թ��ĵ��߳�
    set_maze_long(15);

	//��ڷ���(�����ڶ���)
    set_entry_dir("north");

	//�������������ӷ���
    set_link_entry_dir("north");

	//�������������ӵ�����
    set_link_entry_room(__DIR__"maple_s");

	//��������������ӷ���
    set_link_exit_dir("south");

	//��������������ӵ�����
    set_link_exit_room(__DIR__"maple_e");

	//��ڷ��������
    set_entry_short("������");

	//��ڷ�������
	set_entry_desc(@LONG
����һƬ���ķ����֣�ֻ���紵Ҷ����ɳɳ�������ƺ�
���е�ˮ����Ϣ��
LONG
);

	//���ڷ��������
    set_exit_short("������");

	//���ڷ�������
	set_exit_desc(@LONG
����һƬ���ķ����֣�ֻ���紵Ҷ����ɳɳ�������ƺ�
���е�ˮ����Ϣ��
LONG
);

	//�Թ�����Ķ�����
    set_maze_room_short("������");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
����һƬ���ķ����֣�ֻ���紵Ҷ����ɳɳ�������ƺ�
���е�ˮ����Ϣ��
LONG
);

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
        set_outdoors(1);
}
