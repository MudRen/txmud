// Room: /u/w/wangs/b/kai149.c

inherit ROOM;

void create()
{
	set("short", "�ھִ�Ժ");
	set("long", @LONG
Ժ������ѷ���ʮ�����ò�ϯ���ŵĿ��ڳ�����ϯ�ϻ�����
ѩ������������£�б����һ�潴ɫ���ߵ����죬���紵����
�����죬ʹ�˼����ֱ治���ý�����������������ϻ�������ʨ
�ӡ���Ժ�ﲻʱ�д�����Ƥ������ʦ�������еĺ��˼����ƣ���
���⳨���½󣬺����ڱ�ʾ���ǲ����䡣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai150",
  "south" : __DIR__"kai142",
  "west" : __DIR__"kai152",
  "east" : __DIR__"kai151",
]));
        set("objects",([
        __DIR__"npc/wb": 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
