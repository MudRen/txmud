// Room: /wiz/louth/a/huaner_xiaoyuan.c

inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
����һ��������С��԰��Ժ�����������Ϸ�Ҳ�ѵ�һ������
���ݣ�Ժǽ����������������ʵһ���徲���ǵ��������ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"fyyg",
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
