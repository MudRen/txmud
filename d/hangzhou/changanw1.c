// Room: /d/hangzhou/changanw1.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�������ڳǱ��ĳ������ϣ������򱱲�Զ���Ǻ��ݸ��ı���
���ˣ��������Կ������ٵ��������̴ҴҶ�����������ûʲô
�ر𷱻��ĵط�������һЩ���ֺš�
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"silkshop.c",
  "west" : __DIR__"changanw2",
  "east" : __DIR__"cross",
  "north" : __DIR__"restaurant.c",
]));

	setup();
	replace_program(ROOM);
}
