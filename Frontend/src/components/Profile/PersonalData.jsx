import styles from "./CSS/profile.module.css";

export default function PersonalData() {
  return (
    <div>
      <div className={styles.title}>Datos personales</div>
      <div className={styles.welcome}>
        Lorem ipsum dolor, sit amet consectetur adipisicing elit. Nam non
        deserunt quaerat, deleniti dolorem sapiente impedit illum nisi maiores,
        atque obcaecati et dolores! Deserunt, minima. Sapiente voluptatum ipsam
        quo assumenda!
      </div>
    </div>
  );
}
