// Room: /u/w/wangs/b/kai64.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������ֺ�ᶫ�����ѿ���Ƿֳ����롣�����һ��������
һ�����кӴӳ��д����������Ծ����Ӷ࣬����м����ݡ���
ׯ֮��Ľ������ǳ��о�����������������ֵĺ�ȥ����������
�ֲ��˴��СС���ټ���̣�������ʳס����Ӧ�о��С��˴���
��������䳡��������һ�ҿ���ꡣ
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai36",
  "west" : __DIR__"kai2",
  "east" : __DIR__"kai65",
]));
        set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 2,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
