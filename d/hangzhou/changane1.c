// Room: /d/hangzhou/changane1.c

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
  "west" : __DIR__"cross",
  "south" : __DIR__"douhuashop",
  "east" : __DIR__"changane2",
  "north" : __DIR__"baozishop",
]));

	setup();
	replace_program(ROOM);
}
