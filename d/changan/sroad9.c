// Room: /d/changan/sroad9.c

inherit ROOM;

void create()
{
	set("short", "�ϰ����");
	set("long", @LONG
���Ǿ����ϱ�ֱͨ�ʹ����ϰ������Ҳ�ǳ�����ͨ����˵��
�����ٵ�֮һ����ʱ���г�͢�еĿ����˾�����Ҫ�����ǳ���
�����ǵĹ�Ա���������ûرܡ�������ÿ���ߵ�����·�ϣ�����
�ɵ�սս�����������������ǻ���֣�����ֱͨ�ʹ������ţ���
����һ�ҿ�ջ�����治Զ����С�����ˡ�
LONG
	);

	set("outdoors", "changan");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"hu_bank",
  "south" : __DIR__"sroad4",
  "west" : __DIR__"kezhan",
  "north" : __DIR__"shroad2",
]));

	set("objects",([
	__DIR__"npc/beggar" : 1,
	NPC_DIR"xunpu" : 2,
]));

	setup();
	replace_program(ROOM);
}
