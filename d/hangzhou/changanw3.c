// Room: /d/hangzhou/changanw3.c

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
  "west" : __DIR__"changanw4",
  "south" : __DIR__"medecineshop",
  "east" : __DIR__"changanw2",
  "north" : __DIR__"flowershop",
]));

	setup();
	replace_program(ROOM);
}
