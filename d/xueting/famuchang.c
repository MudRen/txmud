// famuchang.c  edit by pian

inherit ROOM;
void create()
{
	set("short", "��ľ��");
	set("long", @LONG
ѩͤ������һ��С���֣�Ҳ��ѩͤ���Է����ķ�ľ��������
�ոտ�����������������ܼ�ª������������﷥ľ��Ȼ��ѩͤ
���ϵĵ�����ȥ���ۣ�����Ǯ����������� famu ���з�ľ����
LONG
        );
	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"palace_path2",
	//"east" : __DIR__"diggroom2",
]));
	setup();
}
void init()
{
        add_action("do_famu", "famu");
}
int do_famu()
{
        object me,ob,*inv;
        int i,s,sk;
        me = this_player();
        sk = me->query_skill("luban");
        sk = sk + sk;
        
        if(me->query("kee")<20)
        	return notify_fail("������������ˣ���������Ϣһ�°ɡ�\n");
        if(me->query("gin")<20)
        	return notify_fail("��ľ��������ˣ���������Ϣһ�°ɡ�\n");

        //��ѯ�����û���ھ򹤾ߡ�
        inv = all_inventory(me);
        s=0;
        for(i=0; i<sizeof(inv); i++)
	{
		if ( inv[i]->name() == "��ɽ��" ) {s=s+1;}
	}
	if (s<1)
		return notify_fail("  ��û�з�ľ���ߣ���ô��ľ�أ�\n");
	// ��ѯover
	
        
        me->start_busy(2);
        message_vision("$N����ɽ������������������ȥ����\n", me);
        
        // ֱ�Ӽӳ����������ϵͳ����
        i = me->query("kar") + me->query("str") + me->query("int");
        
	
        //5
        if ((sk>50) && (random(sk+i))>((sk+70)*994/1000))
	{
		message_vision("$N�õ�һ�����ľ!!!\n", me);
                me->receive_damage("kee", 10);
        	me->receive_damage("gin", 10);
                me->improve_skill("luban", 100);
                ob = new("/d/obj/wood/huanghui_mu");      
                ob->move(me);
                return 1;
        }
        
        //6
        if ((sk>20) && (random(sk+i))>((sk+65)*990/1000))
	{
		message_vision("$N�õ�һ��ѩ��ľ!!!\n", me);
                me->receive_damage("kee", 10);
        	me->receive_damage("gin", 10);
                me->improve_skill("luban", 30);
                ob = new("/d/obj/wood/xuesong_mu");      
                ob->move(me);
                return 1;
        }
        
        //7
        if ((random(sk+i))>((sk+65)*9/10))
	{
		message_vision("$N�õ�һ������ľ!!!\n", me);
                me->receive_damage("kee", 10);
	        me->receive_damage("gin", 10);
                me->improve_skill("luban", 15);
                ob = new("/d/obj/wood/yangliu_mu");      
                ob->move(me);
                return 1;
        }
        
        message_vision("$N�����ֱ۷��飬����$N��ôҲû�п�������\n",me);
        me->receive_damage("kee", 10);
        me->receive_damage("gin", 10);
        me->improve_skill("luban", 3);
        return 1;        
}