// Room: /d/hangzhou/linchaifang.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
����һ��񷿣���������˲����Լ�һЩ�������֮���
���ߣ��ݽǴ���һ���ݿ���Ӧ�������ס�ĵط���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"linyuanzi",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
