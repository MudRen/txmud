// Room: /d/path5/kch30.c

inherit ROOM;

void create()
{
	set("short", "�����±�");
	set("long", @LONG
��ò������ߵ�����ֱ���ǰ���ͱھ����ˡ����ƴ��ж�
��ɽ��Ȼ���٣�������֮����ͷ����һ��̵��ȴ����Ҳû������
�����졣�㲻������һ���亹����Ҫ����ȥ�ɲ����ˡ�һ����ϸ
�Ĵ�ʯ��մ��򶫱ߵ��ͱڣ�û��ʮ����ջ��ǲ��ߵĺá�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"kch31",
  "west" : __DIR__"kch29",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
