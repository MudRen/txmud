// Room: /wiz/find/huapu/rukou.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ���ľ���С��·��·�߳����������С�ݣ����治
Զ��һ��������ɵ�դ���š�
LONG
	);

	set("exits",([
	"north" : __DIR__"hua_pu/entry",
	"south" : __DIR__"road3",
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
