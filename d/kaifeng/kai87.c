// Room: /u/w/wangs/b/kai87.c

inherit ROOM;

void create()
{
	set("short", "��վ");
	set("long", @LONG
�����ǿ��⸮�ټҵ���վ�����ڿ�����ҵ������ټҵ���
վ�������顢�ż�֮��Ķ����ǳ���Ѹ�١���ȫ���������ںܶ�
����Ҳͨ�������һЩ��Ҫ�������͵���أ���Ȼ���ٸ���Ҫ��
Ǯ�ġ����ﲻͣ������ʹ�����������һ�ɷ�æ�ľ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai86",
]));

	setup();
	replace_program(ROOM);
}
