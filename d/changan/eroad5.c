// /d/changan/eroad5  ���½�

inherit ROOM;

void create()
{
        set("short", "���½�");
        set("long", @LONG
���ﳤ���ǵĶ���֣��붫���Ų�Զ���������ס���ˣ���
���Ǻܸ�������Ҳ����˵�����ǳ�����ƶ���ס�ĵط�����Զ��
�м��������С������Ϸ�ţ��ֱ���һ�����ϵ��ϸ�����������
�߻�������½��д����ϱ����죬������һ��ѧ�ݣ���ʱ������
�������ʵĶ�������
LONG
        );

	set("exits", ([
                "north"           : __DIR__"eroad6",
                "south"           : __DIR__"eroad4",
]) );
	set("outdoors","changan");

	setup();
	replace_program(ROOM);
}
