// Room: /wiz/louth/c/fdjie2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǳɶ��ĸ����֡����������跻������Ʈ���Ĳ���������
�����С��ϱ���������Թᴩ���������֡�
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fdjie1",
  "east" : __DIR__"mingchafang",
  "north" : __DIR__"fdjie3",
]));

	set("objects",([
	NPC_DIR"xunpu" : 3,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
