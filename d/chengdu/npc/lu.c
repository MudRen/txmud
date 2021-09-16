// lu.c

inherit NPC;

mixed ask_me(object);

void create()
{
        set_name("½����", ({ "lu youming" }) );
        set("gender", "����" );
        set("age", 56);
        set("long", "����һλ������С��ͷ������������
ɣ�������ܿ�������������\n");

	set(NO_KILL, 1);

	set("inquiry",([
	"�޻���" : (: ask_me :),
	"�޻�����" : (: ask_me :),
]));

        set("combat_exp", 1000);

	set_skill("unarmed",20);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

mixed ask_me(object who)
{
	mapping q;

	if(!mapp(q = who->query("quest/tangmen_quest"))
	|| (q["name"] != "�޻�����") )
		return "�Ҽ��������ÿ��ͽ���ô��������Ҫ���������Ǯ�ء�";

	if(q["lu_give"])
		return "���Ǹ���һ���ˣ���������ô�࣡";

	if(q["lu_asked"])
		return "���Ǻ���˵�������ˣ���ô���صĶ������ܰ׸��㡣";

	tell_object(who, "
½����˵�����Ҽ�����޻��������Һò����ײŴ�������
���Ի�ģ�ÿ��ͽ���ô������������Ȼ���Ƽұ���Ҫ��
���������һ�����ӣ�������Ҫ�Ȱ���һ��æ���⼸���
���������Ҽҵ�һ�顺�ױ�������Ҳ��͵�ˣ����ܲ���
�����һ�����\n");

	q["lu_asked"] = 1;

	q["hint"] += "\t����½Ա���һر�͵�ġ��ױ������񡻣�Ȼ�󽻻�������";

	return 1;
}

protected void refresh_inv()
{
	object *inv;
	int n;

	if(n = sizeof(inv = filter_array(all_inventory(this_object()), (: $1->query("id") != "cloth" :))))
		for(int i=0; i<n; i++)
			destruct(inv[i]);
}

int accept_object(object me, object ob)
{
	mapping q;
	object whg;

	if(!mapp(q = me->query("quest/tangmen_quest"))
	|| (q["name"] != "�޻�����")
	|| !q["entered_hy"]
	|| (base_name(ob) != __DIR__"obj/baiyu") )
		return 0;

	if( q["get_wuhuaguo"]
#ifdef WIZARD_FLAG
	|| (ob->query_wiz_flag() && !wizardp(me))
#endif
	|| (ob->query_master() != me->query("id")) )
		tell_object(me, "½Ա��ҡҡͷ˵�������ٱ����û�������ô���£�
                  ���Ÿ���С���ﵱ���հɡ�\n");

	else
	{
		q["get_wuhuaguo"] = 1;
		tell_object(me, "½Ա����˵�˵��������������������ǼҵĴ��ұ���лл���ˡ�\n");
		whg = new(__DIR__"obj/wuhuaguo");
		if(!whg->move(me) && !whg->move(environment()))
			destruct(whg);
	}

	if(find_call_out("refresh_inv") <= 0)
		call_out("refresh_inv", 3);
	return 1;
}
