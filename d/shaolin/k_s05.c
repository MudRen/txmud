// Room: /wiz/uudd/path2/k_s05.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
��ɽ���е�С·����ľ�ݴ������Ѵ��У�ʱ��ת��ɽ�ǣ�ʱ
û�����֡�����·�������Ǳ����ý�̤�����ģ��еĽ�����һ�㣬
�еĵط�խһ�㣬��̫�����ü�Ӳ�Ļ�����ϴ���ӡ�Ų�֪��˭
�ȳ����Ľ�ӡ��·���ߵĲݴ���ϤϤ�������ƺ���ʲô����Ҫ��
����һ�㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"k_s06",
  "northeast" : __DIR__"k_s04",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}