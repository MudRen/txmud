// Room: /u/w/wangs/b/kai65.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������ֺ�ᶫ�����ѿ���Ƿֳ����롣�����һ��������
һ�����кӴӳ��д����������Ծ����Ӷ࣬����м����ݡ���
ׯ֮��Ľ������ǳ��о�����������������ֵĺ�ȥ����������
�ֲ��˴��СС���ټ���̣�������ʳס����Ӧ�о��С��˴���
���������ĳ���������ǧ���Ժ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
// "south" : __DIR__"kai67",
  "north" : __DIR__"kai66",
  "west" : __DIR__"kai64",
  "east" : __DIR__"kai68",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
