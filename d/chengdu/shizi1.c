// Room: /wiz/louth/c/shizi1.c

inherit ROOM;

void create()
{
	set("short", "ʮ��·��");
	set("long", @LONG
�����ǳɶ������ʮ��·�ڣ�ÿ���������������ϡ�������
�ɶ��ı��š������߿���һֱͨ���ɶ�Ѳ�����š���������ᴩ
�ɶ�����������·��
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fuenlu",
  "west" : __DIR__"wmlu5",
  "east" : __DIR__"wmlu4",
  "north" : __DIR__"ndoor",
]));

	set("objects",([
	NPC_DIR"xunpu" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
