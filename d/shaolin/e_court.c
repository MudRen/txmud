// Room: /d/shaolin/e_court.c

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", @LONG
�����������µĶ���Ժ��Ժ��һ�Ÿߴ�İ�������˵�Ǵ�Ħ
�����ڽ�������ʱ�������ˣ���������������Ժ�ӣ���ʹ��ʢ��
Ҳ˿�����������ȡ����������Ǳ����ң�������Ϣ�ң�����
���ǹ�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"bingqiku",
  "east" : __DIR__"sleeproom",
  "west" : __DIR__"rroad3",
]));
	set("valid_startroom", 1);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
