// promote.c
// updated by doing

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string old_status, new_status;
	int my_level, ob_level, level;

        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;

	if (! arg || sscanf(arg, "%s %s", arg, new_status) != 2)
		return notify_fail("ָ���ʽ��promote <ʹ����> <�ȼ�>\n");

	if (wiz_level(new_status) < 0)
		return notify_fail("û�����ֵȼ���\n");

	if (! objectp(ob = present(arg, environment(me)))
           || ! playerp(ob))
		return notify_fail("��ֻ�ܸı�ʹ���ߵ�Ȩ�ޡ�\n");

	if ((string)me->query("id") != "ivy"
           && wiz_level(me) < wiz_level(new_status))
		return notify_fail("��û������Ȩ����\n");

	old_status = wizhood(ob);

	seteuid(getuid());
	if (! (SECURITY_D->set_status(ob, new_status)))
		return notify_fail("�޸�ʧ�ܡ�\n");

	message_vision("$N��$n��Ȩ�޴� " + old_status + " ��Ϊ " +
		       new_status + " ��\n", me, ob);
	seteuid(getuid());
	ob->setup();

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : promote <ĳ��> (Ȩ�޵ȼ�)

��������Ȩ�޵ȼ�, (player) (immortal) (apprentice) (wizard)
(arch) (admin)
һ�� admin ������Ȩ�����κεȼ����� arch ֻ�������� arch��
HELP );
    return 1;
}