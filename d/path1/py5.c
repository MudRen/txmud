// Room: /d/path1/py5.c

inherit ROOM;

string go_enter(object me);

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������᫵�ɽ·�������С�̧ͷ��ȥ��������һ����ɽ��
ɽ����ɫ�Ĵ����к�����ʲô�����ڻζ���������һ�������ɵ�
�ӿ�Ų���
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"py6",
  "east" : __DIR__"py4",
  "north" : (: go_enter :),
]));
	set("outdoors", "path1");
	setup();
}

string go_enter(object me)
{
	if(!me || !me->query_temp("pass_changan_dutu"))
		return __DIR__"shanao";

	//me->delete_temp("pass_changan_dutu");
	return "/d/paiyun/up1";
}
