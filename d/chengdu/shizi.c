// Room: /wiz/louth/c/shizi.c

inherit ROOM;

void create()
{
	set("short", "ʮ��·��");
	set("long", @LONG
�����ǳɶ��ϲ���ʮ��·�ڡ������������Ǳ����¡�����
��Զ�ǳɶ��ǵ��ϳ��š������������ͨ����������·��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jguanlu1",
  "south" : __DIR__"sdoor",
  "east" : __DIR__"jguanlu5",
  "north" : __DIR__"guangbaosi",
]));
        set("objects",([
        __DIR__"npc/luren" : 1,
	NPC_DIR"xunpu" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
