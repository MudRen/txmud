// Room: /d/fengtian/xm1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������Ƿ���ٸ����ڵأ���������Ƚ��ྲ������û��̫
��ĵ��̣��Ƚϴ�ĵ��̾��Ƿ��������ھ֡���Զ�ھ֡�����
��һЩ����ĸ���Ҳס�����
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"biao",
  "south" : __DIR__"lukou",
  "east" : __DIR__"jiuguan",
  "north" : __DIR__"xm2",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}