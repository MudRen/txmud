// Room: /wiz/louth/c/fdjie3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǳɶ��ĸ����֡������������ߵ�����·��������һֱ
�ߵ������ֵľ�ͷ��������ǳɶ�����������ܽ��¥�������ǳ�
���Ķ����š�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fdjie2",
  "west" : __DIR__"furuilou",
  "east" : __DIR__"edoor",
  "north" : __DIR__"fdjie4",
]));

	set("outdoors","chengdu");

        set("objects",([
        NPC_DIR"stdnpc/stdnpc_4" : 3,
]));

	setup();
	replace_program(ROOM);
}
