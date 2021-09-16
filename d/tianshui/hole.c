// Room: /d/tianshui/hole.c

inherit VRM_SERVER;

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room( LIGHT_ROOM );

	//�Թ�������Ĺ��
	//set_maze_npcs(__DIR__"npc/maque");

	//�Թ��ĵ��߳�
	set_maze_long(20);

	//��ڷ���(�����ڶ���)
	set_entry_dir("south");

	//�������������ӷ���
	set_link_entry_dir("south");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"enter_hole");

	//��������������ӷ���
	set_link_exit_dir("north");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"xianjing_entry");

	//��ڷ��������
	set_entry_short("����");

	//��ڷ�������
	set_entry_desc(@LONG
����һ����ɭɭ�Ĵ�ɽ�������涴�׶�������������ֱ��һ
���Ի���ʯ�����������ˮ�飬���Ϸǳ���Ţ��
LONG
);

	//���ڷ��������
	set_exit_short("����");

	//���ڷ�������
	set_exit_desc(@LONG
����һ����ɭɭ�Ĵ�ɽ�������涴�׶�������������ֱ��һ
���Ի���ʯ�����������ˮ�飬���Ϸǳ���Ţ��
LONG
);

	//�Թ�����Ķ�����
	set_maze_room_short("����");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
����һ����ɭɭ�Ĵ�ɽ�������涴�׶�������������ֱ��һ
���Ի���ʯ�����������ˮ�飬���Ϸǳ���Ţ��
LONG
);

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	//set_outdoors(1);
}
