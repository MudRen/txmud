// Room: /wiz/louth/c/fdjie1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǳɶ������֡��������ǳɶ�������ի���ϱ��������
�ᴩ�����ɶ�����ĸ����֡�
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jguanlu8",
  "north" : __DIR__"fdjie2",
]));
        set("objects",([
        __DIR__"npc/luren" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
