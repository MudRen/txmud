// Room: /d/huanggong/nanm.c

inherit ROOM;

void create()
{
        set("short", "�ʹ�����");
        set("long", @LONG
������ǻʳǵ����š�ÿ����������ٹ��ɴ˽���ʹ��ȴ�
�����糯�����ŵ������Ǹ�ʮ���׵ĳ�ǽ����ǽ���ߣ���̻Ի�
�������˻ʼҵ����ɡ�һ���������ʨ�����ڳ��ŵ����ߣ�����
�ŵ�����������Ȩ����

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/changan/jingsq1",
  "north" : __DIR__"daolu1",
]));
        set(SAFE_ENV, 1);
        set("outdoors", "huanggong");
	set("objects",([
	__DIR__"npc/yulin" : 2,
]));

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "north" || dir == "n")
		return notify_fail("���־�Уͦ��һ��˵�������ʹ����أ�ƽ����ղ��ý��룡��\n\n");
	else
		return ::valid_leave(me,dir);
}