// Room: /d/huanggong/beim.c

inherit ROOM;

void create()
{
        set("short", "�ʹ�����");
        set("long", @LONG
������Ǵӻʹ�ͨ�����ǵ����һ���Ż���Ҳ�ǽ���ʹ���
�ؾ�֮·��ƽʱ����ɭ�ϡ��ʹ����һЩ�ճ���ƷҲ��ͨ������
������ڵġ����˱��ž��Ǿ����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"shenwm",
	"north" : "/d/changan/jingsq2",
	"west" : "/d/changan/yibinguan",
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
	if(dir == "south" || dir == "s")
		return notify_fail("���־�Уͦ��һ��˵�������ʹ����أ�ƽ����ղ��ý��룡��\n\n");
	else
		return ::valid_leave(me,dir);
}
