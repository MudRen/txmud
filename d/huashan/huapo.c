// Room: /d/huashan/huapo.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����µĻ��£�����ȫ����ʯ����ɳ����Զ��������
���ˮ�����㲻���ӿ��˽Ų�����ǰ��ȥ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"xiaolu8",
  "westup" : __DIR__"sl_dong",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
