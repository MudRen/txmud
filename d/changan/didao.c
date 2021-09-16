// Room: /d/changan/didao.c

inherit VRM_SERVER;

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room( LIGHT_ROOM );

	//�Թ�������Ĺ��
	//set_maze_npcs(__DIR__"npc/maque");

	//�Թ��ĵ��߳�
	set_maze_long(10);

	//��ڷ���(�����ڶ���)
	set_entry_dir("west");

	//�������������ӷ���
	set_link_entry_dir("up");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"zhubao_behind");

	//��������������ӷ���
	set_link_exit_dir("east");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"under_hg");

	//��ڷ��������
	set_entry_short("�ص�");

	//��ڷ�������
	set_entry_desc(@LONG
������һ��������ʪ�ĵص������Ե�ǽ���Ϲ��ŵ��ˮ�飬
���ϲ����˽�ӡ���ƺ��������˴������߹���
LONG
);

	//���ڷ��������
	set_exit_short("�ص�");

	//���ڷ�������
	set_exit_desc(@LONG
������һ��������ʪ�ĵص������Ե�ǽ���Ϲ��ŵ��ˮ�飬
���ϲ����˽�ӡ���ƺ��������˴������߹���
LONG
);

	//�Թ�����Ķ�����
	set_maze_room_short("�ص�");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
������һ��������ʪ�ĵص������Ե�ǽ���Ϲ��ŵ��ˮ�飬
���ϲ����˽�ӡ���ƺ��������˴������߹���
LONG
);

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	//set_outdoors(1);
}
