// Room: /d/fengtian/xunbu.c

inherit ROOM;

void create()
{
	set("short", "Ѳ��Ӫ");
	set("long", @LONG
����Ѳ��Ӫ���𼩲��ﷸ������Ѳ��Ӫ���������ֵ���Ѳ
��������ǽ�Ϲ���Ѳ���õ������Ϳ쵶��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guanlu3",
]));

	set("objects",([
		NPC_DIR"xunpu" : 2,
]));

	setup();
	replace_program(ROOM);
}
