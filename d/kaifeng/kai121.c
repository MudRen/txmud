// Room: /u/w/wangs/b/kai121.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������겢���Ǻܴ󣬵��ſ�лл�ĳ��ż���÷������
÷������ʱ��˿������������÷�������㣬ʹ��ƮƮ���ɣ���֪
���ںδ������ӵ���ʷ�ܳ�����˵����֮һ�ĺ������õ������
��������ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai119",
]));
        set("objects",([
        __DIR__"npc/xboss": 1,
]));

	setup();
	replace_program(ROOM);
}
