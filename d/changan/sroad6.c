// /d/changan/sroad6  �����

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǳ����ǵ��ϴ�֣��ߵ�������Ѿ����Ǻܶ��ˣ�ż
Ȼ�м���ǣ�����ڵ��˴Ҵҵ��߹��������ڳ��Ÿ���������Ƚ�
��������Խ�������Զ�����������Խ�١����������ⰲ���Ĵ�
���ϣ��о�ȴ����һ����ͬ���ɴ��������򶫣���Ȼ���ϴ�֡�
LONG
        );

	set("exits", ([
		"north" : __DIR__"zahuopu",
                "west" : __DIR__"sroad5",
                "east" : __DIR__"sroad7",
]) );

	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/out_vendor" : 1,
]));

        setup();
	replace_program(ROOM);
}
