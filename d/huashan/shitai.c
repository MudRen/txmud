// Room: /d/huashan/shitai.c

inherit ROOM;

void create()
{
	set("short", "ʯ̨");
	set("long", @LONG
���������һ��ʯ̨���ʹ�һ���С������ȥ��Щ��ů�ĸ�
���������������Ƴɵġ�������ô������ƺ�������ܡ�������
ȥ���濴���ɣ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"dongkou",
  "north" : __DIR__"dongtian",
]));

set("item_desc", ([
	"��" : "��������ȥ����ϸ���򴲿�ȥ��ֻ�����Ĳ������
һ��С�֡������´������㲻������һ����\n",
]));
	setup();
	replace_program(ROOM);
}
