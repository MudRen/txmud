// Room: huashan gongmen.c

inherit ROOM;

void create()
{
	set("short", "��ϼ����");
	set("long",@LONG
����һ�����ư���Ĺ��������һ����ֺ��ң���������
����Ŀ��--����ϼ������������ǻ�ɽ�ɵĴ����ˡ��ſڷ���
����ֻ����������ʯʨ�ӡ����Ŷ�����һƬ��������Ĳݵأ���
����һƬ�����֡�ʯ���ϰ���һֻ�޴��ͭ����һ�ɶ�ߵĻ���
�����衣
    ��˵ͭ���Ѿ�ȼ�����ϰ��꣬Ҳ��֪�������������±�Ǩ��
LONG
);

	set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"guangw1",
	"east": __DIR__"guange1",
	"north":__DIR__"doorgd",
]));

	set(SAFE_ENV,1);

	set("objects",([
	__DIR__"npc/dizi" : 2,
]));

	set("outdoors", "huashan_zx");
	setup();
}

int valid_leave(object ob,string dir)
{
	if(!ob || !stringp(dir))
		return 1;

	if( (dir == "north" || dir == "west")
        && ob->query("class") != "huashan"
	&& mapp(ob->query("family"))
        && !wizardp(ob) )
                return notify_fail("��������������ס��˵���������صأ��ǻ�ɽ���Ӳ������ڣ���\n");

        else
                return ::valid_leave(ob,dir);
}
