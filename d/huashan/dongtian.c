// Room: /d/huashan/dongtian.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ֻ��һ�������Ĵ������������һ��ʯ�����Ա߻�������ʯ
�ʣ���Ȼ�����в�ֻһ��������������ڴ����Ľ��仹��������
ľ���������ڳ���δ�ã��Ѿ�������ʹ�ˡ���������һ��ʯ�ݣ�
���治֪����Щʲô��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"shibi",
  "south" : __DIR__"shitai",
  "east" : __DIR__"shiwu",
]));

	setup();
	replace_program(ROOM);
}
