// Room: /u/w/wangs/b/kai12.c

inherit ROOM;

void create()
{
	set("short", "���к���");
	set("long", @LONG
����˼�⣬���к����ֵ���Ȼȫ�������ˡ���Զ����������
��ʲô������ӱ���ŷ������к�Ե�ε����ˡ��Ӱ��ߵ�������
��������������������̸�����֦��б�죬�е�������Ȼ����
�ں�ˮ֮�У��ںӵ���խ�ĵط���������������������һ����
��������У�һ������С�����Ѷ������ɲ���������֮��ô��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"kai11",
  "northeast" : __DIR__"kai13",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
