// Room: /d/changan/wuguan.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
������ǳ�����ݣ��ſڸ߸ߵ������Ʈ��һ���ɫ���죬
������һ������ġ��䡱�֡����ڳ�����������䣬�������۰�
�ջ��Ǹ��𶼰ѵ����͵�����ѧһЩ�书����������ݵ����䳡��
������ž�������֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"nroad3",
  "east"  : __DIR__"wuchang",
]));

	set("objects",([
	__DIR__"npc/dizi" : 2,
	__DIR__"npc/jiaotou" : 1,
]));
	setup();
	replace_program(ROOM);
}
