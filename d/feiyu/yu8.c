// Room: /u/w/wangs/a/yu8.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
���Ǽ䲻��Ĳ񷿣��������ľ���Ѿ����չ��ˣ�ǽ��
���ż��ѡ��񵶡���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yu18",
]));

	setup();
	replace_program(ROOM);
}
