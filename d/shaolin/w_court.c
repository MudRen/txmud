// Room: /d/shaolin/w_court.c

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", @LONG
�����������µ�����Ժ����Ϊ��ի�úܽ������Ըо������
ɮ�˶���æµ������������������ˮ�ģ���˵ģ��ܻ�ģ���ȴ
˿�������û��ң�����ƺ���֪���Լ�����ʲô������ʲô����
Ҳ�����������ɲ�����������еİɡ������������ǲ񷿣���
�ǹ�����������ի�ã�������һƬ�����͵Ĳ˵ء�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zhaitang",
  "south" : __DIR__"caidi",
  "east" : __DIR__"lroad3",
  "west" : __DIR__"chaifang",
]));
	set("valid_startroom", 1);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
