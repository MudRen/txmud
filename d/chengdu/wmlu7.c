// Room: /wiz/louth/c/wmlu7.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����������·���ϱ���һ�Һܴ�����棬�Ǿ����ǳɶ�����
����ǳ�ׯ���������߹ᴩ�����ɶ�����������·��
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wmlu8",
  "south" : __DIR__"chouzhuang",
  "east" : __DIR__"wmlu6",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
