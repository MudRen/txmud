// Room: guodaoe2.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long",@LONG
����һ�����������Ļ��ȣ������ϻ��Ķ��ǵ���������
�����Ǳ��ɵ�ʲô��ʰɡ����Ȼ���������ǰԺ��ǰԺ��ʵ����
һ����С�Ļ�԰���ߵ�������񽥾�������Ҳ��ʼ��ʪ������
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"guodaoe",
	"northeast" : __DIR__"guodaoe3",
	"south":__DIR__"sleephome",
]));
	set("outdoors", "huashan_zx");
	setup();
}

int valid_leave(object ob,string dir)
{
        if(!ob || !stringp(dir))
                return 1;

        if( (dir == "south")
        && ob->query("class") != "huashan"
        && !wizardp(ob) )
                return notify_fail("�ǻ�ɽ���Ӳ������ڣ���\n");

        else
                return ::valid_leave(ob,dir);
}
