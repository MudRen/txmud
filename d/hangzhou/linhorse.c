// Room: /d/hangzhou/linhorse.c

inherit ROOM;

void create()
{
	set("short", "��Ȧ");
	set("long", @LONG
������������Ȧһ���ſ����������ƥ����ƥƥ�����׳��
ëɫ���ʣ��е���ͷ��˻���еĵ��װ�β��������Ա�����ǰ�ϧ
��Щ��ƥ��������Ҳȷʵƥƥ����ǧ����һ�ĺ���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"linyuanzi",
]));

	set("objects",([
	RIDE_DIR"zouluo" : 1,
]));

	setup();
	replace_program(ROOM);
}
