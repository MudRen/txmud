// Room: /u/w/wangs/b/kai102.c

inherit ROOM;

void create()
{
	set("short", "ľ�ĵ�");
	set("long", @LONG
���Сľ�ĵ���ڿ����Ͻ��ұߵĽֽ��ϡ������խ��ǽ��
�ϵ�ʯ��Ҳ�ѵ����䣬�����ǿ���š�ľ�ĵꡱ���ֵ����ң���
�Ǹ��಻����ҡҡ��׹��������ȥ�������ۣ������ڿ������һ
��ȴ����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai100",
]));
        set("objects",([
        __DIR__"npc/mboss": 1,
]));

	setup();
	replace_program(ROOM);
}
